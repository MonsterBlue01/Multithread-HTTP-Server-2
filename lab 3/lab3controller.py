# Lab 3 Skeleton
#
# Based on of_tutorial by James McCauley

from pox.core import core
import pox.openflow.libopenflow_01 as of
from pox.lib.packet.arp import arp
from pox.lib.packet.ipv4 import ipv4
from pox.lib.packet.tcp import tcp

log = core.getLogger()

class Firewall (object):
    def __init__ (self, connection):
        self.connection = connection
        connection.addListeners(self)

    def do_firewall(self, packet, packet_in):
        msg = of.ofp_flow_mod()
        msg.match = of.ofp_match.from_packet(packet)

        if isinstance(packet.next, ipv4):
            if isinstance(packet.next.next, tcp):
                # Rule 1: Accept any IPv4 TCP traffic
                msg.actions.append(of.ofp_action_output(port=of.OFPP_FLOOD))
            else:
                # Rule 3: Drop any other type of IPv4 traffic
                msg.priority = 1
        elif isinstance(packet.next, arp):
            # Rule 2: Accept any ARP traffic
            msg.actions.append(of.ofp_action_output(port=of.OFPP_FLOOD))
        else:
            # Rule 3: Drop any other type of traffic
            msg.priority = 1

        self.connection.send(msg)

    def _handle_PacketIn(self, event):
        packet = event.parsed
        if not packet.parsed:
            log.warning("Ignoring incomplete packet")
            return

        packet_in = event.ofp
        self.do_firewall(packet, packet_in)

def launch():
    def start_switch(event):
        log.debug("Controlling %s" % (event.connection,))
        Firewall(event.connection)
    core.openflow.addListenerByName("ConnectionUp", start_switch)
