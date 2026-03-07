////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class OnPostXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(OnPostXG, XGNodeVk)
    public:
        OnPostXG(){}
        ~OnPostXG(){}
        
        static void init_meta()
        {
            auto w = writer<OnPostXG>();
            w.category("Messaging");
            w.label("On Post");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Post");
            w.symbol("yq/symbol/xgbasic.sym#trigger");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(OnPostXG)
