////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UserSpatial3UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/lineedit.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition3.hpp>
#include <yq/assetvk/command/user3/User3HCommand.hpp>
#include <yq/assetvk/command/user3/User3PCommand.hpp>
#include <yq/assetvk/command/user3/User3RCommand.hpp>
#include <yq/assetvk/command/user3/User3XCommand.hpp>
#include <yq/assetvk/command/user3/User3YCommand.hpp>
#include <yq/assetvk/command/user3/User3ZCommand.hpp>
#include <yq/assetvk/spatial/UserSpatial3.hpp>
#include <yq/assetvk/spatial/UserSpatial3Data.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UserSpatial³UI)

namespace yq::tachyon {
    void UserSpatial³UI::init_meta()
    {
        auto w = writer<UserSpatial³UI>();
        w.description("UIEditor for UserSpatial³");
        w.edits<UserSpatial³>();
        w.field("Heading", &UserSpatial³UI::h);
        w.field("Pitch", &UserSpatial³UI::p);
        w.field("Roll", &UserSpatial³UI::r);
        w.field("X", &UserSpatial³UI::x);
        w.field("Y", &UserSpatial³UI::y);
        w.field("Z", &UserSpatial³UI::z);
        //w.field("Position", &UserSpatial³UI::position);
    }
    
    UserSpatial³UI::UserSpatial³UI(UIFlags flags)
    {
    }
    
    UserSpatial³UI::UserSpatial³UI(const UserSpatial³UI& cp) : UIEditor(cp)
    {
    }
    
    UserSpatial³UI* UserSpatial³UI::clone() const
    {
        return new UserSpatial³UI(*this);
    }

    void    UserSpatial³UI::h()
    {
        const UserSpatial³Snap* sn  = dynamic_cast<const UserSpatial³Snap*>(snap());
        if(!sn)
            return;
        
        //  Once we get an algebraic control, we'll use that
        std::string   v  = sn->h.algebra;
        if(im::lineedit("##HAlgebra", v, {
            .flags = ImGuiInputTextFlags_EnterReturnsTrue,
        }))
            send(new User³HCommand({.target=sn->self}, { v }));
    }
    
    void    UserSpatial³UI::p()
    {
        const UserSpatial³Snap* sn  = dynamic_cast<const UserSpatial³Snap*>(snap());
        if(!sn)
            return;

        //  Once we get an algebraic control, we'll use that
        std::string   v  = sn->p.algebra;
        if(im::lineedit("##PAlgebra", v, {
            .flags = ImGuiInputTextFlags_EnterReturnsTrue,
        }))
            send(new User³PCommand({.target=sn->self}, { v }));
    }
    
    void    UserSpatial³UI::r()
    {
        const UserSpatial³Snap* sn  = dynamic_cast<const UserSpatial³Snap*>(snap());
        if(!sn)
            return;

        //  Once we get an algebraic control, we'll use that
        std::string   v  = sn->r.algebra;
        if(im::lineedit("##RAlgebra", v, {
            .flags = ImGuiInputTextFlags_EnterReturnsTrue,
        }))
            send(new User³RCommand({.target=sn->self}, { v }));
    }
    
    void    UserSpatial³UI::x()
    {
        const UserSpatial³Snap* sn  = dynamic_cast<const UserSpatial³Snap*>(snap());
        if(!sn)
            return;

        //  Once we get an algebraic control, we'll use that
        std::string   v  = sn->x.algebra;
        if(im::lineedit("##XAlgebra", v, {
            .flags = ImGuiInputTextFlags_EnterReturnsTrue,
        }))
            send(new User³XCommand({.target=sn->self}, { v }));
    }
    
    void    UserSpatial³UI::y()
    {
        const UserSpatial³Snap* sn  = dynamic_cast<const UserSpatial³Snap*>(snap());
        if(!sn)
            return;

        //  Once we get an algebraic control, we'll use that
        std::string   v  = sn->y.algebra;
        if(im::lineedit("##YAlgebra", v, {
            .flags = ImGuiInputTextFlags_EnterReturnsTrue,
        }))
            send(new User³YCommand({.target=sn->self}, { v }));
    }
    
    void    UserSpatial³UI::z()
    {
        const UserSpatial³Snap* sn  = dynamic_cast<const UserSpatial³Snap*>(snap());
        if(!sn)
            return;

        //  Once we get an algebraic control, we'll use that
        std::string   v  = sn->z.algebra;
        if(im::lineedit("##ZAlgebra", v, {
            .flags = ImGuiInputTextFlags_EnterReturnsTrue,
        }))
            send(new User³ZCommand({.target=sn->self}, { v }));
    }
    
}
