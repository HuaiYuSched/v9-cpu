#Setup page
Setup page in v9 is more simple then in x86. Reserve memory for page directory and four basic pages as globe char array. Because of alignment, we need to alloc 6M memory for 5 page(page directory and four pages). Then initialize this pages:   
1. Get the address of reserved memory, and align it by add 4095 then unmask the bits less then 4M.  
2. Setup page 0, 1, 2 and 3, get the address and mask the properties as present, writable and in user mode.   
3. Assign this pages' address to page directory.   
4. Use instruction PDIR load this page directory address to CPU.   
