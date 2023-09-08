#ifndef __DEBOUNCE__H__
#define __DEBOUNCE__H__


namespace Utils
{
    class IButtonPressCallBack
    {
        public:
            virtual void ButtonPressedCallback(int id) = 0;
    };

    class Debounce
    {
        int _pin;

        int _debounceTime;

        unsigned long _lastStateChangeTime;

        bool _stateChangeInProgress;

        bool _callBackInvoked;

        IButtonPressCallBack* _callbackObject;

    public:
        Debounce(int pin, int time);

        void Update();

        void SetCallback(IButtonPressCallBack* func);
    };
}

#endif  //!__DEBOUNCE__H__