////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/action/CallbackAction.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/Payload.hpp>

namespace yq::tachyon {

    /*! \brief Callback on the specified tachyon
    */
    template <SomeTachyon T>
    class PayloadCallbackAction : public CallbackAction {
    public:
        typedef void (T::*FN)(const Payload&);
        
        PayloadCallbackAction(FN fn) : m_function(fn) 
        {
            assert(m_function);
        }
        
        PayloadCallbackAction(const PayloadCallbackAction& cp) : m_function(cp.m_function) 
        {
        }
        
        ~PayloadCallbackAction()
        {
        }
    
        virtual bool  action(Payload& pp) const override
        {
            if(!m_function)
                return false;
            T*  t   = dynamic_cast<T*>(pp.source);
            if(!t)
                return false;
            (t->*m_function)(pp);
            return true;
        }

    protected:
        PayloadCallbackAction* clone() const 
        {
            return new PayloadCallbackAction(*this);
        }
    private:    
        FN  m_function;
    };
}

