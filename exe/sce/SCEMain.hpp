////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/app/YMain.hpp>

using namespace yq;
using namespace yq::tachyon;

class SCEMain : public YMain {
    YQ_TACHYON_DECLARE(SCEMain, YMain)
    Q_OBJECT
public:

    using PostStartupFN = std::function<void(SCEMain&)>;

    // TODO... project....
    SCEMain();
    SCEMain(PostStartupFN&&); // TODO
    ~SCEMain();
    
    static void init_meta();
    
protected:
    virtual Execution   setup(const Context&) override;
    
    virtual SCEMain*     newMain() override;

private:
    PostStartupFN           m_startup;
};

extern TypedID     gFileIO;
