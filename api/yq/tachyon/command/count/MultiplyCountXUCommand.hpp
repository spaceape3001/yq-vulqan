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
    class MultiplyCountˣUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCountˣUCommand, CountCommand)
    public:
        MultiplyCountˣUCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCountˣUCommand(const MultiplyCountˣUCommand&, const Header&);
        MultiplyCountˣUCommand(const Header&);
        ~MultiplyCountˣUCommand();

    private:
        unsigned  m_δx = 0.0;
        
        MultiplyCountˣUCommand(const MultiplyCountˣUCommand&) = delete;
        MultiplyCountˣUCommand(MultiplyCountˣUCommand&&) = delete;
        MultiplyCountˣUCommand& operator=(const MultiplyCountˣUCommand&) = delete;
        MultiplyCountˣUCommand& operator=(MultiplyCountˣUCommand&&) = delete;
    };
}
