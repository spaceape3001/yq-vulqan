////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class SendMessageXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(SendMessageXG, XGNodeVk)
    public:
        SendMessageXG(){}
        ~SendMessageXG(){}
        
        static void init_meta()
        {
            auto w = writer<SendMessageXG>();
            w.category("Messaging");
            w.label("Send Message");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Message");
            w.symbol("yq/symbol/xgbasic.sym#command");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(SendMessageXG)
