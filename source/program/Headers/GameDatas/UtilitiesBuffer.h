
template<class type>
struct Buffer_{
    int mCount;
    int mCapacity;
    type* mpArray;
};

template<class A>
struct RingBuf{
    A* mpArray;
    int mMax;
    int mOffset;
    int mCount;
};