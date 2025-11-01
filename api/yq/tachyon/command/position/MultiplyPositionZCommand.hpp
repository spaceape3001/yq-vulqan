////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class MultiplyPositionᶻCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionᶻCommand, PositionCommand)
    public:
        MultiplyPositionᶻCommand(const Header&, double);
        
        static void init_meta();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionᶻCommand(const MultiplyPositionᶻCommand&, const Header&);
        MultiplyPositionᶻCommand(const Header&);
        ~MultiplyPositionᶻCommand();

    private:
        double  m_δz = 0.0;
        
        MultiplyPositionᶻCommand(const MultiplyPositionᶻCommand&) = delete;
        MultiplyPositionᶻCommand(MultiplyPositionᶻCommand&&) = delete;
        MultiplyPositionᶻCommand& operator=(const MultiplyPositionᶻCommand&) = delete;
        MultiplyPositionᶻCommand& operator=(MultiplyPositionᶻCommand&&) = delete;
    };
}
