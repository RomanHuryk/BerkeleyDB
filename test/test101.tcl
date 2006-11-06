# See the file LICENSE for redistribution information.
#
# Copyright (c) 2000,2006 Oracle.  All rights reserved.
#
# $Id: test101.tcl,v 12.4 2006/11/01 00:54:02 bostic Exp $
#
# TEST	test101
# TEST	Test for functionality near the end of the queue
# TEST	using test070 (DB_CONSUME).
proc test101 { method {nentries 1000} {txn -txn} {tnum "101"} args} {
	if { [is_queueext $method ] == 0 } {
		puts "Skipping test$tnum for $method."
		return;
	}
	eval {test070 $method 4 2 $nentries WAIT 4294967000 $txn $tnum} $args
}
