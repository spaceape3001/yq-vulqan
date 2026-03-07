////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class OnMessageXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(OnMessageXG, XGNodeVk)
    public:
        OnMessageXG(){}
        ~OnMessageXG(){}
        
        static void init_meta()
        {
            auto w = writer<OnMessageXG>();
            w.category("Messaging");
            w.label("On Message");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Message");
            w.symbol("yq/symbol/xgbasic.sym#trigger");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(OnMessageXG)
