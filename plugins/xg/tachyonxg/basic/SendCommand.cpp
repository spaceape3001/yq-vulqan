////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class SendCommandXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(SendCommandXG, XGNodeVk)
    public:
        SendCommandXG(){}
        ~SendCommandXG(){}
        
        static void init_meta()
        {
            auto w = writer<SendCommandXG>();
            w.category("Messaging");
            w.label("Send Command");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Command");
            w.symbol("yq/symbol/xgbasic.sym#command");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(SendCommandXG)
