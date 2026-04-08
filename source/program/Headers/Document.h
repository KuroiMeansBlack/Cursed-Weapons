struct typedParam
{
    void* virtualFunctionPtr;
    char* mpParentPath;
};

struct Document
{
    char _pad1[0x150];
    typedParam* mpTypedParam;
};
		