////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class OnReplyXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(OnReplyXG, XGNodeVk)
    public:
        OnReplyXG(){}
        ~OnReplyXG(){}
        
        static void init_meta()
        {
            auto w = writer<OnReplyXG>();
            w.category("Messaging");
            w.label("On Reply");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Reply");
            w.symbol("yq/symbol/xgbasic.sym#trigger");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(OnReplyXG)
