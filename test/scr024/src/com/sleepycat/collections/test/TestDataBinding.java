/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 2002,2006 Oracle.  All rights reserved.
 *
 * $Id: TestDataBinding.java,v 12.4 2006/11/01 00:54:12 bostic Exp $
 */

package com.sleepycat.collections.test;

import com.sleepycat.bind.EntryBinding;
import com.sleepycat.db.DatabaseEntry;

/**
 * @author Mark Hayes
 */
class TestDataBinding implements EntryBinding {

    public Object entryToObject(DatabaseEntry data) {

        if (data.getSize() != 1) {
            throw new IllegalStateException("size=" + data.getSize());
        }
        byte val = data.getData()[data.getOffset()];
        return new Long(val);
    }

    public void objectToEntry(Object object, DatabaseEntry data) {

        byte val = ((Number) object).byteValue();
        data.setData(new byte[] { val }, 0, 1);
    }
}
