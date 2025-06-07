////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyPositionˣCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionˣCommand, PositionCommand)
    public:
        MultiplyPositionˣCommand(const Header&, double);
        
        static void init_info();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionˣCommand(const MultiplyPositionˣCommand&, const Header&);
        MultiplyPositionˣCommand(const Header&);
        ~MultiplyPositionˣCommand();

    private:
        double  m_δx = 0.0;
        
        MultiplyPositionˣCommand(const MultiplyPositionˣCommand&) = delete;
        MultiplyPositionˣCommand(MultiplyPositionˣCommand&&) = delete;
        MultiplyPositionˣCommand& operator=(const MultiplyPositionˣCommand&) = delete;
        MultiplyPositionˣCommand& operator=(MultiplyPositionˣCommand&&) = delete;
    };
}
