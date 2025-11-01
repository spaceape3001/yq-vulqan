////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMinSizeˣCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeˣCommand, SizeCommand)
    public:
        MultiplyMinSizeˣCommand(const Header&, double);
        
        static void init_meta();
        
        double  δx() const { return m_δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeˣCommand(const MultiplyMinSizeˣCommand&, const Header&);
        MultiplyMinSizeˣCommand(const Header&);
        ~MultiplyMinSizeˣCommand();

    private:
        double  m_δx = 0.0;
        
        MultiplyMinSizeˣCommand(const MultiplyMinSizeˣCommand&) = delete;
        MultiplyMinSizeˣCommand(MultiplyMinSizeˣCommand&&) = delete;
        MultiplyMinSizeˣCommand& operator=(const MultiplyMinSizeˣCommand&) = delete;
        MultiplyMinSizeˣCommand& operator=(MultiplyMinSizeˣCommand&&) = delete;
    };
}
