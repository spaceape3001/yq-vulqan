////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyPositionCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionCommand, PositionCommand)
    public:
        MultiplyPositionCommand(const Header&, double);
        
        static void init_meta();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionCommand(const MultiplyPositionCommand&, const Header&);
        ~MultiplyPositionCommand();
        MultiplyPositionCommand(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyPositionCommand(const MultiplyPositionCommand&) = delete;
        MultiplyPositionCommand(MultiplyPositionCommand&&) = delete;
        MultiplyPositionCommand& operator=(const MultiplyPositionCommand&) = delete;
        MultiplyPositionCommand& operator=(MultiplyPositionCommand&&) = delete;
    };
}
