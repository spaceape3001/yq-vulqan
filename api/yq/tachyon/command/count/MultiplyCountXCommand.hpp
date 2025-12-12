////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyCountˣCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCountˣCommand, CountCommand)
    public:
        MultiplyCountˣCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCountˣCommand(const MultiplyCountˣCommand&, const Header&);
        MultiplyCountˣCommand(const Header&);
        ~MultiplyCountˣCommand();

    private:
        unsigned  m_δx = 0.0;
        
        MultiplyCountˣCommand(const MultiplyCountˣCommand&) = delete;
        MultiplyCountˣCommand(MultiplyCountˣCommand&&) = delete;
        MultiplyCountˣCommand& operator=(const MultiplyCountˣCommand&) = delete;
        MultiplyCountˣCommand& operator=(MultiplyCountˣCommand&&) = delete;
    };
}
