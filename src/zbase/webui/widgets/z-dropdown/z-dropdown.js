/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Laura Schlimmer
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
var DropDownComponent = function() {
  this.createdCallback = function() {
    var base = this;

    this.initHeaderItem();

    //close dropdown only if click event is outside
    this.addEventListener('click', function(e) {
      e.stopPropagation();
    }, false);
  };

  this.attributeChangedCallback = function(attr, old_val, new_val) {
    this.initHeaderItem();
  };

  /**
    * Returns either the selected items data-value attr or text content
    *
    * @return {String} csv
    */
  this.getValue = function() {
    var items = this.querySelectorAll("z-dropdown-item[data-selected]");
    var value = [];

    for (var i = 0; i < items.length; i++) {
      if (items[i].hasAttribute('data-value')) {
        value.push(items[i].getAttribute('data-value'));
      } else {
        value.push(items[i].textContent);
      }
    }

    return value.join(",");
  };

  /**
    * Marks for each value the matching dropdown-item as selected
    *
    * @param {Array} values
    */
  this.setValue = function(values) {
    var _this = this;

    values.forEach(function(v) {
      var item = _this.querySelector("z-dropdown-item[data-value='" + v + "']");

      if (item) {
        item.setAttribute('data-selected', 'selected');

        var checkbox = item.querySelector("z-checkbox");

        if (checkbox) {
          checkbox.setAttribute('data-active', 'active');
        }
      }
    });

    this.setHeaderValue();
  }

  // Checks if a header_elem exists and renders one if not
  this.initHeaderItem = function() {
    if (this.querySelector("z-dropdown-input")) {
      return this.renderSearchable();
    }

    var base = this;
    var selected_item = this.querySelector("z-dropdown-item[data-selected]");
    var header_elem = this.querySelector("z-dropdown-header");

    if (!header_elem) {
      header_elem = document.createElement("z-dropdown-header");
      this.insertBefore(header_elem, this.firstChild);
    }

    //render header value
    if (!header_elem.querySelector("z-drodpown-header-value")) {
      header_elem.appendChild(document.createElement(
        "z-dropdown-header-value"));
    }

    //render header icon
    if (!header_elem.querySelector("z-dropdown-header-icon")) {
      var icon = document.createElement("z-dropdown-header-icon");
      icon.innerHTML = "<i class='fa fa-caret-down'></i>";
      header_elem.appendChild(icon);
    }

    var onClick = function(e) {
      e.stopPropagation();
      base.toggleDropdown();
    };

    if (!header_elem.hasAttribute('data-blank')) {
      this.setHeaderValue();
    }
    header_elem.addEventListener('click', onClick, false);

    if (this.hasAttribute('data-hover')) {
      this.addEventListener(
        'mouseover',
        base.showDropdown.bind(base),
        false);

      this.addEventListener(
        'mouseout',
        base.hideDropdown.bind(base),
        false);
    }
  };

  // Copies the selected items html to the header_elem
  this.setHeaderValue = function() {
    var header = this.querySelector("z-dropdown-header-value");

    if (header.hasAttribute('data-static')) {
      return;
    }

    var innerHTML = "";

    //multi selectable dropdown
    if (this.classList.contains('checkbox')) {
      var selected_items = this.querySelectorAll("z-dropdown-item[data-selected]");

      for (var i = 0; i < selected_items.length; i++) {
        if (i > 0) {
          innerHTML += ", ";
        }

        innerHTML += selected_items[i].innerText || selected_items[i].textContent;
      }

    } else {

      var selected_item = this.querySelector("z-dropdown-item[data-selected]");
      if (!selected_item) {

        var preselection = this.getAttribute('data-preselected');
        //set preselected item
        if (preselection) {
          var preselected_item = this.findItemByValue(preselection);

          preselected_item.setAttribute('data-selected', 'selected');
          innerHTML = preselected_item.innerHTML;

        } else {
          //z-dropdown has initial not selectable header
          if (header.innerHTML.length > 0) {
            return;
          }

          //set first z-dropdown-item as header value
         innerHTML = this.querySelector("z-dropdown-item").innerHTML;
        }
      } else {
        //set items input value as html header
        if (selected_item.hasAttribute('data-input-select')) {
          var input = selected_item.querySelector("input");
          innerHTML = input.value;

        } else {
          //set selected_item's html as header (standard case)
          innerHTML = selected_item.innerHTML;
        }
      }
    }

    header.innerHTML = innerHTML;
  };


  this.toggleDropdown = function() {
    if (this.hasAttribute('data-active')) {
      this.hideDropdown();
    } else {
      this.showDropdown();
    }
  };

  this.hideDropdown = function() {
    var hover_item = this.querySelector("z-dropdown-item.hover");

    this.removeAttribute('data-active');

    if (hover_item) {
      hover_item.classList.remove('hover');
    }

    this.fireCloseEvent();

    //remove global event listener
    if (!this.querySelector("z-input")) {
      this.unsetKeyNavigation(window);
    }
  };

  /**
    * Close open Items (e.g. dropdowns) on editor click
    */
  this.closeActiveItems = function(callback) {
    var active_items = document.querySelectorAll("[data-active]");

    for (var i = 0; i < active_items.length; i++) {
      if (typeof active_items[i].hideDropdown == 'function') {
        active_items[i].hideDropdown();
      }
    }

    callback();
  };

  this.setXValue = function() {
    var items = this.querySelector("z-dropdown-items");
    var pos = items.getBoundingClientRect();
    var margin;


    if (document.body.offsetWidth < pos.right) {
      margin = pos.right - document.body.offsetWidth;

      //visible y-scrollbar
      if (items.scrollHeight > pos.height) {
        margin += 17;
      }

      items.style.marginLeft = "-" + margin + "px";
    }
  }

  this.showDropdown = function() {
    if (this.classList.contains("disabled")) {
      return;
    }

    var _this = this;

    this.closeActiveItems(function() {
      _this.setAttribute('data-active', 'active');
      _this.setXValue();
    });


    if (!this.eventListeners) {
      //set eventListeners only once
      this.setItemEventListeners();
    }

    //set global event listener if not searchable
    if (!this.querySelector("z-input")) {
      this.setKeyNavigation(window);
    }
  };

  this.findItemByValue = function(value) {
    return (this.querySelector(
      "z-dropdown-item[data-value='" + value + "']"));
  };

  this.setItemEventListeners = function() {
    var base = this;
    var items = this.querySelectorAll("z-dropdown-item:not([data-input-select])");
    var input_items = this.querySelectorAll('z-dropdown-item[data-input-select]');

    for (var i = 0; i < items.length; i++) {
      items[i].onclick = function() {
        base.onItemClick(this);
      }
    }


    for (var i = 0; i < input_items.length; i++) {
      input_items[i].addEventListener('click', function(e) {
        e.stopPropagation;
      }, false);

      var input = input_items[i].querySelector("input");
      var checkbox = input_items[i].querySelector("z-checkbox");
      var check = input_items[i].querySelector("[data-check]");
      if (check) {
        console.log(check);
      }
      var item = input_items[i];

      if (input) {
        input.addEventListener('keydown', function(e) {
          e.stopPropagation();

          if (e.keyCode == 13) {
            if (checkbox) {
              checkbox.setAttribute('data-active', 'active');
            }

            base.onItemClick(item);

          }
        }, false);
      }
    }

    this.eventListeners = true;
  };


  this.onItemClick = function(item) {
    if (!item) {
      return;
    }

    var input_elem = this.querySelector("z-input");
    var selected = true;

    //multi-selectable dropdown with checkboxes
    if (this.classList.contains('checkbox')) {
      var checkbox = item.querySelector("z-checkbox") || item.querySelector("[data-check]");

      if (item.hasAttribute('data-selected')) {
        selected = false;
        item.removeAttribute('data-selected');
        console.log(checkbox);
        checkbox.removeAttribute('data-active');

        //not completely unselectable dropdown
        if (this.hasAttribute('data-force-select') &&
            !this.querySelector('z-dropdown-item[data-selected]')) {

          var default_select = this.querySelector('z-dropdown-item[data-default]');

          if (default_select) {
            default_select.setAttribute('data-selected', 'selected');
            checkbox = default_select.querySelector('z-checkbox');

            if (checkbox) {
              checkbox.setAttribute('data-active', 'active');
            }
          }
        }
      } else {
        checkbox.setAttribute('data-active', 'active');
      }

    } else {
      var prev_item = this.querySelector("z-dropdown-item[data-selected]");

      if (prev_item) {
        prev_item.removeAttribute('data-selected');
      }
    }

    if (selected) {
      item.setAttribute("data-selected", 'selected');
    }

    if (input_elem) {
      input_elem.setAttribute('data-value', item.innerHTML);
    } else {
      this.setHeaderValue();
    }

    this.fireClickEvent(item, selected);

    // FIXME: don't fire this here for data-multiselect
    this.hideDropdown();

    var change_ev = new CustomEvent(
        "change", {
          detail : {
            value: this.getValue()
          },
          bubbles: true,
          cancelable: true
        });

    this.dispatchEvent(change_ev);
  };

  this.fireClickEvent = function(item, selected) {
    var name = (selected) ? "z-dropdown-item-click" : "z-dropdown-item-unselect";

    var ev = new CustomEvent(name, {
      detail : {'text' : item.textContent},
      bubbles: true,
      cancelable: true
    });
    item.dispatchEvent(ev);
  };

  this.fireCloseEvent = function() {
    var ev = new CustomEvent('z-dropdown-close', {
      bubbles: true,
      cancelable: true
    });

    this.dispatchEvent(ev);
  }


  /*********************** Key Navigation **********************************/
  this.onKeyDown = function(e) {
    var input = this.querySelector("z-input");
    var visibleScrollbar = this.visibleScrollbar();

    switch (e.keyCode) {
      case 38:
        this.keyNavigation('up', visibleScrollbar);
        break;
      case 40:
        this.keyNavigation('down', visibleScrollbar);
        break;
      case 13:
        this.onItemClick(this.querySelector("z-dropdown-item.hover"), true);
        break;
      default:
        if (input) {
          this.showFilteredDropdownItems(input.getValue());
        }
        break;
    }
  }

  this.setKeyNavigation = function(elem) {
    var that = this;
    this.keydown_handler = function(e) {
      that.onKeyDown.apply(that, [e]);
      e.preventDefault();
      return false;
    };

    elem.addEventListener('keydown', this.keydown_handler, false);
  };

  this.unsetKeyNavigation = function(elem) {
    elem.removeEventListener('keydown', this.keydown_handler, false);
  };

  this.visibleScrollbar = function() {
    var items = this.querySelector("z-dropdown-items");

    return items.scrollHeight > items.offsetHeight;
  };


  this.keyNavigation = function(direction, visibleScrollbar) {
    var hover_elem = this.querySelector("z-dropdown-item.hover");
    var ref_elem;
    var elem = null;
    var items = this.querySelectorAll("z-dropdown-item");

    if (!hover_elem) {
      if (direction == 'down') {
        //filtered Dropdown can contain hidden items
        if (items[0].classList.contains('hidden')) {
          hover_elem = items[0];
        } else {
          items[0].classList.add('hover');
          return;
        }
      }
    }

    ref_elem = hover_elem;
    for (var i = 0; i < items.length; i++) {

      //down
      if (direction == 'down') {
        elem = ref_elem.nextElementSibling;

        //wrap around and mark first item
        if (!elem) {
          elem = items[0];

          if (visibleScrollbar) {
            var d_items = this.querySelector("z-dropdown-items");
            d_items.scrollTop = 0;
          }

        } else {

          if (visibleScrollbar) {
            var d_items = this.querySelector("z-dropdown-items");
            d_items.scrollTop = d_items.scrollTop + (d_items.offsetHeight / items.length);
          }
        }

      //up
      } else {
        elem = ref_elem.previousElementSibling;

        //wrap around and mark last item
        if (!elem) {
          elem = items[items.length - 1];

          if (visibleScrollbar) {
            var d_items = this.querySelector("z-dropdown-items");
            d_items.scrollTop = d_items.scrollHeight;
          }

        } else {

          if (visibleScrollbar) {
            var d_items = this.querySelector("z-dropdown-items");
            d_items.scrollTop = d_items.scrollTop - (d_items.offsetHeight / items.length);
          }

        }
      }

      if (elem.classList.contains('hidden')) {
        ref_elem = elem;
      } else {
        elem.classList.add('hover');
        hover_elem.classList.remove('hover');
        return;
      }
    }
  };

  /******************** Searchable Dropdown *************************/

  this.renderSearchable = function() {
    var dropdown_input = this.querySelector("z-dropdown-input");
    if (!dropdown_input) {
      return;
    }

    var base = this;
    var input = document.createElement("z-input");
    var placeholder = dropdown_input.getAttribute('data-placeholder');
    var selected_item = this.querySelector("z-dropdown-item[data-selected");

    if (placeholder) {
      input.setAttribute('data-placeholder', placeholder);
    }

    if (selected_item) {
      input.setAttribute('data-value', selected_item.textContent);
    }

    dropdown_input.appendChild(input);
    input.addEventListener('click', function(e) {
      e.stopPropagation();
      this.setAttribute('data-value', "");
      base.showDropdown();
    }, false);

    this.setKeyNavigation(input);
  };

  this.showFilteredDropdownItems = function(value) {
    var items = this.querySelectorAll("z-dropdown-item");
    var value = value.toLowerCase();

    for (var i = 0; i < items.length; i++) {
      if (items[i].textContent.toLowerCase().indexOf(value) > -1) {
        items[i].classList.remove('hidden');
      } else {
        items[i].classList.add('hidden');
      }
    }

    this.showDropdown();
  };
};

var proto = Object.create(HTMLElement.prototype);
DropDownComponent.apply(proto);
document.registerElement("z-dropdown", { prototype: proto });
