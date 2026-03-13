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
    class MultiplyCountʷUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCountʷUCommand, CountCommand)
    public:
        MultiplyCountʷUCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCountʷUCommand(const MultiplyCountʷUCommand&, const Header&);
        MultiplyCountʷUCommand(const Header&);
        ~MultiplyCountʷUCommand();

    private:
        unsigned  m_δw = 0.0;
        
        MultiplyCountʷUCommand(const MultiplyCountʷUCommand&) = delete;
        MultiplyCountʷUCommand(MultiplyCountʷUCommand&&) = delete;
        MultiplyCountʷUCommand& operator=(const MultiplyCountʷUCommand&) = delete;
        MultiplyCountʷUCommand& operator=(MultiplyCountʷUCommand&&) = delete;
    };
}
