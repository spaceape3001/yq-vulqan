////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/action/CallbackAction.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    /*! \brief Callback on the specified tachyon
    */
    template <SomeTachyon T>
    class StdCallbackAction : public CallbackAction {
    public:
        typedef void (T::*FN)();
        
        StdCallbackAction(FN fn) : m_function(fn) 
        {
            assert(m_function);
        }
        
        StdCallbackAction(const StdCallbackAction& cp) : m_function(cp.m_function) 
        {
        }
        
        ~StdCallbackAction()
        {
        }
    
        virtual bool  action(Payload& pp) const override
        {
            if(!m_function)
                return false;
            T*  t   = dynamic_cast<T*>(pp.source);
            if(!t)
                return false;
            (t->*m_function)();
            return true;
        }

    protected:
        StdCallbackAction* clone() const 
        {
            return new StdCallbackAction(*this);
        }
    private:    
        FN  m_function;
    };
}

