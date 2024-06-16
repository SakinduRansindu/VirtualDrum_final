#ifndef HANDLER
#define HANDLER

class Handler{

    private:
        typedef void (*HandleOp)(void);
        HandleOp upFunc;
        HandleOp downFunc;
        HandleOp selectFunc;
        HandleOp backFunc;

    public:
        Handler();
        void setFucnctions(HandleOp upFunc, HandleOp downFunc, HandleOp selectFunc, HandleOp backFunc);
        void Up();
        void set_UpFunc(HandleOp upFunc);
        void Down();
        void set_DownFunc(HandleOp downFunc);
        void Select();
        void set_SelectFunc(HandleOp selectFunc);
        void Back();
        void set_BackFunc(HandleOp backFunc);

};

#endif