from pox.core import core
import pox.openflow.libopenflow_01 as of

log = core.getLogger()

class Final (object):
    """
    A Firewall object is created for each switch that connects.
    A Connection object for that switch is passed to the __init__ function.
    """
    def __init__ (self, connection):
        # Keep track of the connection to the switch so that we can
        # send it messages!
        self.connection = connection

        # This binds our PacketIn event listener
        connection.addListeners(self)

    def do_final(self, packet, packet_in, port_on_switch, switch_id):
        # Parse the IP and ICMP headers
        ip_header = packet.find('ipv4')
        icmp_header = packet.find('icmp')

        # List of IPs to be protected
        protected_ips = ["10.1.1.10", "10.1.2.20", "10.1.3.30", "10.1.4.40", "10.2.5.50", "10.2.6.60", "10.2.7.70", "10.2.8.80", "10.3.9.90"]
        # Define the new protected IPs for Department B
        protected_ips_B = ["10.2.5.50", "10.2.6.60", "10.2.7.70", "10.2.8.80"]
        # Define the new protected IPs for Department A
        protected_ips_A = ["10.1.1.10", "10.1.2.20", "10.1.3.30", "10.1.4.40"]
        msg = of.ofp_flow_mod()
        msg.match = of.ofp_match.from_packet(packet)
        msg.idle_timeout = 30
        msg.hard_timeout = 30

        # If the packet is an ICMP packet and it's from the untrusted host to one of the protected IPs,
        # send a flow rule to the switch to drop it.
        if ip_header is not None and icmp_header is not None:
            if ip_header.srcip == '106.44.82.103' and str(ip_header.dstip) in protected_ips:
                log.info("Dropping an ICMP packet from Untrusted Host to {}".format(ip_header.dstip))
                msg.buffer_id = packet_in.buffer_id
                self.connection.send(msg)
                return

        # If the packet is an IP packet and it's from the untrusted host to the server, drop it.
        if ip_header is not None:
            if ip_header.srcip == '106.44.82.103' and ip_header.dstip == '10.3.9.90':
                log.info("Dropping an IP packet from Untrusted Host to server")
                msg.buffer_id = packet_in.buffer_id
                self.connection.send(msg)
                return
            
        # If the packet is an ICMP packet and it's from the trusted host to one of the protected IPs in department B,
        # or to the server, send a flow rule to the switch to drop it.
        if ip_header is not None and icmp_header is not None:
            if ip_header.srcip == '108.24.31.112' and str(ip_header.dstip) in protected_ips_B + ['10.3.9.90']:
                log.info("Dropping an ICMP packet from Trusted Host to {}".format(ip_header.dstip))
                msg.buffer_id = packet_in.buffer_id
                self.connection.send(msg)
                return

        # If the packet is an IP packet and it's from the trusted host to the server, drop it.
        if ip_header is not None:
            if ip_header.srcip == '108.24.31.112' and ip_header.dstip == '10.3.9.90':
                log.info("Dropping an IP packet from Trusted Host to server")
                msg.buffer_id = packet_in.buffer_id
                self.connection.send(msg)
                return

        # If the packet is an ICMP packet and it's from Department A to Department B, drop it.
        if ip_header is not None and icmp_header is not None:
            if str(ip_header.srcip) in protected_ips_A and str(ip_header.dstip) in protected_ips_B:
                log.info("Dropping an ICMP packet from Department A to Department B")
                msg.buffer_id = packet_in.buffer_id
                self.connection.send(msg)
                return

        # If the packet is an ICMP packet and it's from Department B to Department A, drop it.
        if ip_header is not None and icmp_header is not None:
            if str(ip_header.srcip) in protected_ips_B and str(ip_header.dstip) in protected_ips_A:
                log.info("Dropping an ICMP packet from Department B to Department A")
                msg.buffer_id = packet_in.buffer_id
                self.connection.send(msg)
                return

        # Otherwise, if it's not from the untrusted host to a protected IP, let it through.
        msg.actions.append(of.ofp_action_output(port = of.OFPP_ALL))
        msg.data = packet_in
        self.connection.send(msg)

    def _handle_PacketIn (self, event):
        """
        Handles packet in messages from the switch.
        """
        packet = event.parsed # This is the parsed packet data.
        if not packet.parsed:
            log.warning("Ignoring incomplete packet")
            return

        packet_in = event.ofp # The actual ofp_packet_in message.
        self.do_final(packet, packet_in, event.port, event.dpid)

def launch ():
    """
    Starts the component
    """
    def start_switch (event):
        log.debug("Controlling %s" % (event.connection,))
        Final(event.connection)
    core.openflow.addListenerByName("ConnectionUp", start_switch)
