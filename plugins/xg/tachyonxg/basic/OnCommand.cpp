////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class OnCommandXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(OnCommandXG, XGNodeVk)
    public:
        OnCommandXG(){}
        ~OnCommandXG(){}
        
        static void init_meta()
        {
            auto w = writer<OnCommandXG>();
            w.category("Messaging");
            w.label("On Command");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Command");
            w.symbol("yq/symbol/xgbasic.sym#trigger");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(OnCommandXG)
