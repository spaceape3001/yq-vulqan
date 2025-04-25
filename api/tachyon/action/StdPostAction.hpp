////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/action/PostAction.hpp>
#include <tachyon/api/Post.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    template <SomePost P>
    class StdPostAction : public PostAction {
    public:
        StdPostAction()
        {
        }
        
        StdPostAction(const StdPostAction& cp) : PostAction(cp) 
        {
        }
        
        ~StdPostAction()
        {
        }
        
        Action* clone() const
        {
            return new StdPostAction(*this);
        }
        
        virtual bool  action(Payload& pp) const
        {
            if(!pp.source)
                return false;
            pp.source->send(new P({.source=*pp.source}));
            return true;
        }
    };
    
}
