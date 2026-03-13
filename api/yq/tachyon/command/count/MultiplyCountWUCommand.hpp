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
    class MultiplyCountʷCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCountʷCommand, CountCommand)
    public:
        MultiplyCountʷCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCountʷCommand(const MultiplyCountʷCommand&, const Header&);
        MultiplyCountʷCommand(const Header&);
        ~MultiplyCountʷCommand();

    private:
        unsigned  m_δw = 0.0;
        
        MultiplyCountʷCommand(const MultiplyCountʷCommand&) = delete;
        MultiplyCountʷCommand(MultiplyCountʷCommand&&) = delete;
        MultiplyCountʷCommand& operator=(const MultiplyCountʷCommand&) = delete;
        MultiplyCountʷCommand& operator=(MultiplyCountʷCommand&&) = delete;
    };
}
