////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyPositionʷCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionʷCommand, PositionCommand)
    public:
        MultiplyPositionʷCommand(const Header&, double);
        
        static void init_meta();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionʷCommand(const MultiplyPositionʷCommand&, const Header&);
        MultiplyPositionʷCommand(const Header&);
        ~MultiplyPositionʷCommand();

    private:
        double  m_δw = 0.0;
        
        MultiplyPositionʷCommand(const MultiplyPositionʷCommand&) = delete;
        MultiplyPositionʷCommand(MultiplyPositionʷCommand&&) = delete;
        MultiplyPositionʷCommand& operator=(const MultiplyPositionʷCommand&) = delete;
        MultiplyPositionʷCommand& operator=(MultiplyPositionʷCommand&&) = delete;
    };
}
