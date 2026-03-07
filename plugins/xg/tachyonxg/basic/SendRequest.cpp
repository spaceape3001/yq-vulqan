////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class SendRequestXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(SendRequestXG, XGNodeVk)
    public:
        SendRequestXG(){}
        ~SendRequestXG(){}
        
        static void init_meta()
        {
            auto w = writer<SendRequestXG>();
            w.category("Messaging");
            w.label("Send Request");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Request");
            w.symbol("yq/symbol/xgbasic.sym#command");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(SendRequestXG)
