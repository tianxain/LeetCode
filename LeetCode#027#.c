int removeElement(int* nums, int numsSize, int val){

    int* src=nums;
    int* dst=nums;
    while(numsSize--)
    {
        if((*src)!=val)
        {
            *dst++=*src++;
        }
        else
        {
            src++;
        }
    }
    return dst-nums;
}
