////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class MultiplyPositionᶻDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionᶻDCommand, PositionCommand)
    public:
        MultiplyPositionᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionᶻDCommand(const MultiplyPositionᶻDCommand&, const Header&);
        MultiplyPositionᶻDCommand(const Header&);
        ~MultiplyPositionᶻDCommand();

    private:
        double  m_δz = 0.0;
        
        MultiplyPositionᶻDCommand(const MultiplyPositionᶻDCommand&) = delete;
        MultiplyPositionᶻDCommand(MultiplyPositionᶻDCommand&&) = delete;
        MultiplyPositionᶻDCommand& operator=(const MultiplyPositionᶻDCommand&) = delete;
        MultiplyPositionᶻDCommand& operator=(MultiplyPositionᶻDCommand&&) = delete;
    };
}
