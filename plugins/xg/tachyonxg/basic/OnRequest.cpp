////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class OnRequestXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(OnRequestXG, XGNodeVk)
    public:
        OnRequestXG(){}
        ~OnRequestXG(){}
        
        static void init_meta()
        {
            auto w = writer<OnRequestXG>();
            w.category("Messaging");
            w.label("On Request");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Request");
            w.symbol("yq/symbol/xgbasic.sym#trigger");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(OnRequestXG)
