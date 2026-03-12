////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMinSizeˣDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeˣDCommand, SizeCommand)
    public:
        MultiplyMinSizeˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeˣDCommand(const MultiplyMinSizeˣDCommand&, const Header&);
        MultiplyMinSizeˣDCommand(const Header&);
        ~MultiplyMinSizeˣDCommand();

    private:
        double  m_δx = 0.0;
        
        MultiplyMinSizeˣDCommand(const MultiplyMinSizeˣDCommand&) = delete;
        MultiplyMinSizeˣDCommand(MultiplyMinSizeˣDCommand&&) = delete;
        MultiplyMinSizeˣDCommand& operator=(const MultiplyMinSizeˣDCommand&) = delete;
        MultiplyMinSizeˣDCommand& operator=(MultiplyMinSizeˣDCommand&&) = delete;
    };
}
