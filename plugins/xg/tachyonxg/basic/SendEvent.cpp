////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class SendEventXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(SendEventXG, XGNodeVk)
    public:
        SendEventXG(){}
        ~SendEventXG(){}
        
        static void init_meta()
        {
            auto w = writer<SendEventXG>();
            w.category("Messaging");
            w.label("Send Event");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Event");
            w.symbol("yq/symbol/xgbasic.sym#command");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(SendEventXG)
