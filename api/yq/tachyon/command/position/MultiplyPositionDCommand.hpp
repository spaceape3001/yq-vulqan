////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyPositionDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionDCommand, PositionCommand)
    public:
        MultiplyPositionDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionDCommand(const MultiplyPositionDCommand&, const Header&);
        ~MultiplyPositionDCommand();
        MultiplyPositionDCommand(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyPositionDCommand(const MultiplyPositionDCommand&) = delete;
        MultiplyPositionDCommand(MultiplyPositionDCommand&&) = delete;
        MultiplyPositionDCommand& operator=(const MultiplyPositionDCommand&) = delete;
        MultiplyPositionDCommand& operator=(MultiplyPositionDCommand&&) = delete;
    };
}
