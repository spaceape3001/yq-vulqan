////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class OnEventXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(OnEventXG, XGNodeVk)
    public:
        OnEventXG(){}
        ~OnEventXG(){}
        
        static void init_meta()
        {
            auto w = writer<OnEventXG>();
            w.category("Messaging");
            w.label("On Event");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Event");
            w.symbol("yq/symbol/xgbasic.sym#trigger");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(OnEventXG)
