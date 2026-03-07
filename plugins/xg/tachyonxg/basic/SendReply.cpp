////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class SendReplyXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(SendReplyXG, XGNodeVk)
    public:
        SendReplyXG(){}
        ~SendReplyXG(){}
        
        static void init_meta()
        {
            auto w = writer<SendReplyXG>();
            w.category("Messaging");
            w.label("Send Reply");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Reply");
            w.symbol("yq/symbol/xgbasic.sym#command");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(SendReplyXG)
