////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/UICommand.hpp>

#include <yq/shape/Size2.hpp>
namespace yq::tachyon {
    class AspectCommand : public UICommand {
        YQ_OBJECT_DECLARE(AspectCommand, UICommand)
    public:
        AspectCommand(const Header&, const Size2I&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

        const Size2I& aspect() const { return m_aspect; }
        int width() const { return m_aspect.x; }
        int height() const { return m_aspect.y; }

    protected:
        AspectCommand(const AspectCommand&, const Header&);
        virtual ~AspectCommand();
        
    private:

        Size2I      m_aspect;

        AspectCommand(const AspectCommand&) = delete;
        AspectCommand(AspectCommand&&) = delete;
        AspectCommand& operator=(const AspectCommand&) = delete;
        AspectCommand& operator=(AspectCommand&&) = delete;
    };
}
