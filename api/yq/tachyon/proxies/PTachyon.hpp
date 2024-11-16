////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Proxy.hpp>

namespace yq::tachyon {
    class PTachyon : public Proxy {
    public:
    
        void        mail(PostCPtr&);
    
    private:
        PTachyon(Tachyon*);
        
    };
}
