#ifndef __REPOSITORY__H__
#define __REPOSITORY__H__
#include "./Interfaces/IRepository.h"

namespace PotStill
{
    class Repository : public Interfaces::IRepository
    {
        int _lowerThreshold;
        int _upperThreshold;
        int _markTime;
        int _spaceTime;
        float _temp;

        int ReadWord(int baseAddress);
        void WriteWord(int baseAddress, int value);

        public:
        Repository();
        
        int GetLowerThreshold() { return _lowerThreshold; };
        void SetLowerThreshold(int value);    
            
        int GetUpperThreshold() { return _upperThreshold; };
        void SetUpperThreshold(int value);           
            
        int GetMarkTime() { return _markTime; };
        void SetMarkTime(int value);       
            
        int GetSpaceTime() { return _spaceTime; };
        void SetSpaceTime(int value);             
    };
}
#endif  //!__REPOSITORY__H__