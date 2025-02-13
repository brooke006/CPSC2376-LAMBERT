# Bugs Found and Fixed

## sumRange function
- Bug: Loop stopped too early with i < end
- Fixed: Changed to i <= end to include last number
- Example: now 1 to 5 gives 15 instead of 10

## containsNegative function
- Bug 1: Loop went too far with i <= size()
- Bug 2: Was checking for positive numbers instead of negative
- Fixed: Changed loop to i < size() and check for < 0

## findMax function  
- Bug 1: Returned 0 for empty vectors
- Bug 2: Loop went past end of vector
- Bug 3: Used >= instead of > for comparison
- Fixed these by:
 - Return -1 for empty vectors
 - Fixed loop bounds
 - Changed to > for finding max
