/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012-2013 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_SCROLLBAR_HPP
#define TGUI_SCROLLBAR_HPP


#include <TGUI/Slider.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API Scrollbar : public Slider
    {
      public:

        typedef SharedWidgetPtr<Scrollbar> Ptr;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Scrollbar();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Scrollbar(const Scrollbar& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~Scrollbar();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        ///
        /// \param right  Instance to assign
        ///
        /// \return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Scrollbar& operator= (const Scrollbar& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget by calling the copy constructor.
        // This function calls new and if you use this function then you are responsible for calling delete.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Scrollbar* clone();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Loads the widget.
        ///
        /// \param configFileFilename  Filename of the config file.
        ///
        /// The config file must contain a Scrollbar section with the needed information.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool load(const std::string& configFileFilename);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Does nothing.
        ///
        /// \param minimum  Unused parameter
        ///
        /// This function is overridden from Slider so that the minimum can't be changed.
        /// The minimum will always stay 0.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMinimum(unsigned int minimum);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Sets a maximum value.
        ///
        /// \param maximum  The new maximum value
        ///
        /// When the minimum value is higher than the new maximum then it will be changed to this new maximum value.
        /// When the value is bigger than (maximum - low value), the value is set to maximum - low value.
        /// The default maximum value is 10.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMaximum(unsigned int maximum);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the current value.
        ///
        /// \param value  The new value
        ///
        /// The value has to be smaller than maximum - low value.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setValue(unsigned int value);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the 'low value'.
        ///
        /// \param lowValue  The new low value.
        ///                  In e.g. a list box, this value is the amount of items that fit inside the list box.
        ///
        /// Until the maximum is bigger than this value, no scrollbar will be drawn.
        /// You can however choose to always draw the scrollbar by calling setAutoHide(false).
        /// The default low value is 6.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setLowValue(unsigned int lowValue);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the low value.
        ///
        /// \see setLowValue
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getLowValue() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes whether the scrollbar should hide automatically or not.
        ///
        /// When true (default), the scrollbar will not be drawn when the maximum is smaller than the low value.
        ///
        /// \param autoHide  Should the scrollbar be invisible when you can't scroll?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setAutoHide(bool autoHide);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns whether the scrollbar is hiding automatically or not.
        ///
        /// When true (default), the scrollbar will not be drawn when the maximum is smaller than the low value.
        /// So when you can't scroll, the scrollbar won't be drawn.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool getAutoHide() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the transparency of the widget.
        ///
        /// \param transparency  The transparency of the widget.
        ///                      0 is completely transparent, while 255 (default) means fully opaque.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTransparency(unsigned char transparency);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnWidget(float x, float y);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void leftMousePressed(float x, float y);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void leftMouseReleased(float x, float y);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void mouseMoved(float x, float y);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        // This function is a (slow) way to set properties on the widget, no matter what type it is.
        // When the requested property doesn't exist in the widget then the functions will return false.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool setProperty(std::string property, const std::string& value);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        // This function is a (slow) way to get properties of the widget, no matter what type it is.
        // When the requested property doesn't exist in the widget then the functions will return false.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool getProperty(std::string property, std::string& value) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        // Returns a list of all properties that can be used in setProperty and getProperty.
        // The second value in the pair is the type of the property (e.g. int, uint, string, ...).
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual std::list< std::pair<std::string, std::string> > getPropertyList() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draws the widget on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Defines specific triggers to Scrollbar.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum ScrollbarCallbacks
        {
            AllScrollbarCallbacks = SliderCallbacksCount - 1, ///< All triggers defined in Scrollbar and its base classes
            ScrollbarCallbacksCount = SliderCallbacksCount
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        // Maximum should be above this value before the scrollbar is needed
        unsigned int m_LowValue;

        // When no scrollbar is needed, should the scrollbar be drawn or stay hidden?
        bool m_AutoHide;

        // Did the mouse went down on one of the arrows?
        bool m_MouseDownOnArrow;

        Texture m_TextureArrowUpNormal;
        Texture m_TextureArrowUpHover;

        Texture m_TextureArrowDownNormal;
        Texture m_TextureArrowDownHover;

        // ListBox, ComboBox and TextBox can access the scrollbar directly
        friend class ListBox;
        friend class ComboBox;
        friend class TextBox;
        friend class ChatBox;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_SCROLLBAR_HPP
