////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIForm.hpp>

namespace yq::tachyon {
    class Frame;
    class Thread;
    struct ThreadData;
    struct ThreadSnap;
}

using namespace yq;
using namespace yq::tachyon;

class MetricsUI : public UIForm {
    YQ_OBJECT_DECLARE(MetricsUI, UIForm)
public:

    static void init_info();

    MetricsUI(UIFlags flags={});
    MetricsUI(const MetricsUI&);
    ~MetricsUI();
    
    virtual MetricsUI* clone() const override;
    
    void    fps();
    void    cameras();
    void    scenes();
    void    models();
    void    rendereds();
    void    lights();
    void    threads();
    void    cycle();
    
    void    render() override;

private:
    const Frame*        m_frame     = nullptr;
    const Thread*       m_thread    = nullptr;
    const ThreadData*   m_data      = nullptr;
    const ThreadSnap*   m_snap      = nullptr;
};

