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
from pox.lib.packet import icmp, ipv4

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
        ip_packet = packet.find('ipv4')
        if ip_packet is not None:  # Check if this is an IP packet.
            if ip_packet.srcip == "106.44.82.103":  # Check if this packet is from the untrusted host.
                icmp_packet = packet.find('icmp')
                if icmp_packet is not None:  # Check if this is an ICMP packet.
                    if (ip_packet.dstip in ["10.1.1.10", "10.1.2.20", "10.1.3.30", "10.1.4.40", 
                                            "10.2.5.50", "10.2.6.60", "10.2.7.70", "10.2.8.80", "10.3.9.90"]):  
                        # If the destination is one of the specified hosts or the server, drop the packet.
                        self.drop_packet(packet, packet_in)
                        return

        # If none of the conditions are met, proceed with the existing logic.
        msg = of.ofp_flow_mod()
        msg.match = of.ofp_match.from_packet(packet)
        msg.idle_timeout = 30
        msg.hard_timeout = 30
        # Do not specify any actions for the flow_mod message. 
        # This means that the switch will not forward these matched packets.
        msg.data = packet_in
        self.connection.send(msg)


    def drop_packet (self, packet, packet_in):
        """
        Drops this packet and optionally installs a flow to continue
        dropping similar packets for a while.
        """
        msg = of.ofp_flow_mod()
        msg.match = of.ofp_match.from_packet(packet)
        msg.idle_timeout = 30
        msg.hard_timeout = 30
        msg.data = packet_in
        self.connection.send(msg)

    def flood_packet (self, packet, packet_in):
        """
        Outputs a packet on all ports.  If the switch supports
        flooding, use that.  Otherwise, send it out on all ports.
        """
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
        packet = event.parsed
        packet_in = event.ofp
        self.do_final(packet, packet_in, event.port, event.connection.dpid)

def launch ():
    """
    Starts the component
    """
    def start_switch (event):
        log.debug("Controlling %s" % (event.connection,))
        Final(event.connection)
    core.openflow

