### Translation Lookaside Buffer

Page 379. Operating Systems Internals and Design Principles 9th Edition - W. Stallings.

The TLB functions in the same way as cache memory  and contains those page table entries that have been most recently used.

Given the virtual address, the processor will first examine the TLB. If the desired page table entry is present (TLB hit), then the frame number is retrieved and the real address is formed. If the desired page table entry is not found (TLB miss), then the processor uses the page number to index the process page table and examine the corresponding page table entry. If the "present bit" is set, then the page is in main memory, and the processor can retrieve the frame number from the page table entry to form the real address

The processor also updates the TLB to include this new page table entry.

Finally, if the present bit is not set, then the desired page in not in main memory and a memory access fault, called a *page fault*, is issued. At this point the OS is invoked to load the needed page and updates the page table.

The figure on page 381 describes the operation of paging and translation lookaside buffer.
