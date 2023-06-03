# Final Skeleton
#
# Hints/Reminders from Lab 3:
#
# To check the source and destination of an IP packet, you can use
# the header information... For example:
#
# ip_header = packet.find('ipv4')
#
# if ip_header.srcip == "1.1.1.1":
#     print "Packet is from 1.1.1.1"
#
# Important Note: the "is" comparison DOES NOT work for IP address
# comparisons in this way. You must use ==.
# 
# To send an OpenFlow Message telling a switch to send packets out a
# port, do the following, replacing <PORT> with the port number the 
# switch should send the packets out:
#
#        msg = of.ofp_flow_mod()
#        msg.match = of.ofp_match.from_packet(packet)
#        msg.idle_timeout = 30
#        msg.hard_timeout = 30
#
#        msg.actions.append(of.ofp_action_output(port = <PORT>))
#        msg.data = packet_in
#        self.connection.send(msg)
#
# To drop packets, simply omit the action.
#

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

    def do_final (self, packet, packet_in, port_on_switch, switch_id):
        # Parse the IP and ICMP packets
        ip = packet.find('ipv4')
        icmp = packet.find('icmp')

        if ip:
            src_ip = str(ip.srcip)
            dst_ip = str(ip.dstip)

            # Rule: Untrusted Host cannot send ICMP traffic to Host 10 to 80, or the Server.
            # Rule: Untrusted Host cannot send any IP traffic to the Server.
            if src_ip == '106.44.82.103':
                if icmp or dst_ip == '10.3.9.90':
                    self.drop_packet(packet, packet_in)
                    return

            # Rule: Trusted Host cannot send ICMP traffic to Host 50 to 80 in Department B, or the Server.
            # Rule: Trusted Host cannot send any IP traffic to the Server.
            if src_ip == '108.24.31.112':
                if icmp and '10.2.' in dst_ip or dst_ip == '10.3.9.90':
                    self.drop_packet(packet, packet_in)
                    return

            # Rule: Hosts in Department A (Host 10 to 40) cannot send any ICMP traffic to the hosts in
            # Department B (Host 50 to 80), and vice versa.
            if icmp and (('10.1.' in src_ip and '10.2.' in dst_ip) or ('10.2.' in src_ip and '10.1.' in dst_ip)):
                self.drop_packet(packet, packet_in)
                return

        # If no rule is triggered, forward the packet normally
        self.forward_packet(packet, packet_in)
        
    def drop_packet(self, packet, packet_in):
        msg = of.ofp_flow_mod()
        msg.match = of.ofp_match.from_packet(packet)
        msg.idle_timeout = 30
        msg.hard_timeout = 30
        msg.data = packet_in
        self.connection.send(msg)

    def forward_packet(self, packet, packet_in):
        msg = of.ofp_flow_mod()
        msg.match = of.ofp_match.from_packet(packet)
        msg.idle_timeout = 30
        msg.hard_timeout = 30
        msg.actions.append(of.ofp_action_output(port = of.OFPP_FLOOD))
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