////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/xgvk/api/XGNodeVkMetaWriter.hpp>

using namespace yq;
using namespace yq::tachyon;

namespace {
    class SendPostXG : public XGNodeVk {
        YQ_OBJECT_DECLARE(SendPostXG, XGNodeVk)
    public:
        SendPostXG(){}
        ~SendPostXG(){}
        
        static void init_meta()
        {
            auto w = writer<SendPostXG>();
            w.category("Messaging");
            w.label("Send Post");
            //w.icon(0, "pp:yq/icon/xg/delay.svg");
            w.description("Detecting for a Post");
            w.symbol("yq/symbol/xgbasic.sym#command");
        }
        
        xg_result_t execute(XGContextVk&)
        {
            return WAIT;    // TODO
        }
    };
}

YQ_OBJECT_IMPLEMENT(SendPostXG)
