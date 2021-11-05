#pragma once


class Mouse
{
   
    public:
        enum ClickState : int
        {
            leftClick = 1,
            rightClick = 2,
            noClick = 0
        };

       static ClickState getClickState();
       static void setClickState(ClickState clickstate);
    private:
        static ClickState click; 
};