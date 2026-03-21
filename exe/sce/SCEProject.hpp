////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/vkqt/XTachyon.hpp>
#include <filesystem>

using namespace yq;
using namespace yq::tachyon;

struct SCEProjectSnap : public TachyonSnap {
};

class SCEProject : public XTachyon<QObject, Tachyon> {
    YQ_TACHYON_SNAP(SCEProjectSnap)
    YQ_TACHYON_DECLARE(SCEProject, Tachyon)
    Q_OBJECT
public:

    SCEProject();
    SCEProject(const std::filesystem::path&);
    ~SCEProject();
    
    static void init_meta();

protected:
    void        snap(SCEProjectSnap&) const;
    
private:

    
};

extern  TypedID   gProjectID;
