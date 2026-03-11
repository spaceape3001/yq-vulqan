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
    class MultiplyPositionˣDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionˣDCommand, PositionCommand)
    public:
        MultiplyPositionˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionˣDCommand(const MultiplyPositionˣDCommand&, const Header&);
        MultiplyPositionˣDCommand(const Header&);
        ~MultiplyPositionˣDCommand();

    private:
        double  m_δx = 0.0;
        
        MultiplyPositionˣDCommand(const MultiplyPositionˣDCommand&) = delete;
        MultiplyPositionˣDCommand(MultiplyPositionˣDCommand&&) = delete;
        MultiplyPositionˣDCommand& operator=(const MultiplyPositionˣDCommand&) = delete;
        MultiplyPositionˣDCommand& operator=(MultiplyPositionˣDCommand&&) = delete;
    };
}
