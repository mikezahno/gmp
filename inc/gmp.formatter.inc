<?php


// /**
//  * Implementation of hook_field_info().
//  */
// function gmp_field_info() {
//   return array(
//     'gmp' => array(
//       'label' => t('Gmp'),
//       'settings' => array(
//         'gmp_location' => variable_get('gmp_location'), // Default Values
//         'gmp_width'    => variable_get('gmp_width'),
//         'gmp_height'   => variable_get('gmp_height'),
//         'gmp_zoom'     => variable_get('gmp_zoom')
//       ),
//       'default_formatter' => 'gmp',
//       'default_widget' => 'gmp_field',
//       'property_type' => 'text',
//     ),
//   );
// }


// /**
//  * Implements hook_field_settings_form().
//  */
// function gmp_field_settings_form($field, $instance, $has_data) {
//   $settings = $field['settings'];

//   $form = array();
//   $form['gmp_location'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Location'),
//     '#size' => 60,
//     '#maxlength' => 128,
//     '#required' => TRUE,
//     '#description' => t('The location defines the place to highlight on the map. It accepts a location as either a place name, address, or place ID.'),
//     '#default_value' => variable_get('gmp_location')
//   );
//   $form['gmp_width'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Width'),
//     '#size' => 8,
//     '#maxlength' => 10,
//     '#required' => TRUE,
//     '#description' => t('In % or px'),
//     '#default_value' => variable_get('gmp_width')
//   );
//   $form['gmp_height'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Height'),
//     '#size' => 8,
//     '#maxlength' => 10,
//     '#required' => TRUE,
//     '#description' => t('In % or px'),
//     '#default_value' => variable_get('gmp_height')
//   );
//   $form['gmp_zoom'] = array(
//     '#type' => 'select',
//     '#title' => t('Zoom Area'),
//     '#description' => t('Accepted values range from 0 (the whole world) to 21 (individual buildings).'),
//     '#default_value' => variable_get('gmp_zoom'),
//     '#options' => _gmp_zoom()
//   );

//   return $form;
// }



// /**
//  * Implements hook_field_formatter_info().
//  */
// function gmp_field_formatter_info() {
//   $info = array(
//     'gmp_field' => array(
//       'label' => t('Gmp Textfield'),
//       'field types' => array('gmp'),
//       'description' => t('Gmp Textfield'),
//       'settings'  => array( //Array of the settings we'll create
//         'gmp_location' => variable_get('gmp_location'), // Default Values
//         'gmp_width'    => variable_get('gmp_width'),
//         'gmp_height'   => variable_get('gmp_height'),
//         'gmp_zoom'     => variable_get('gmp_zoom')
//       ),
//     ),
//   );
//   return $info;
// }

// /**
//  * Implements hook_field_formatter_settings_form().
//  */
// function gmp_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
//   $display = $instance['display'][$view_mode];
//   $settings = $display['settings'];
//   $element = array();
//   $element['gmp_location'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Location'),
//     '#size' => 60,
//     '#maxlength' => 128,
//     '#required' => TRUE,
//     '#description' => t('The location defines the place to highlight on the map. It accepts a location as either a place name, address, or place ID.'),
//     '#default_value' => variable_get('gmp_location')
//   );
//   $element['gmp_width'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Width'),
//     '#size' => 8,
//     '#maxlength' => 10,
//     '#required' => TRUE,
//     '#description' => t('In % or px'),
//     '#default_value' => variable_get('gmp_width')
//   );
//   $element['gmp_height'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Height'),
//     '#size' => 8,
//     '#maxlength' => 10,
//     '#required' => TRUE,
//     '#description' => t('In % or px'),
//     '#default_value' => variable_get('gmp_height')
//   );
//   $element['gmp_zoom'] = array(
//     '#type' => 'select',
//     '#title' => t('Zoom Area'),
//     '#description' => t('Accepted values range from 0 (the whole world) to 21 (individual buildings).'),
//     '#default_value' => variable_get('gmp_zoom'),
//     '#options' => _gmp_zoom()
//   );
//   return $element;
// }

// /**
//  * Implements hook_field_formatter_settings_summary().
//  */
// function gmp_field_formatter_settings_summary($field, $instance, $view_mode) {
//   $display = $instance['display'][$view_mode];
//   $settings = $display['settings'];
//   $summary = t('Button size: @size, Button Type: @type, Button Position: @pos', array(
//     '@location' => $settings['gmp_location'],
//     '@width'    => $settings['gmp_width'],
//     '@height'   => $settings['gmp_height'],
//     '@zoom'     => $settings['gmp_zoom'],

//   ));
//   return $summary;
// }

// /**
//  * Implements hook_field_formatter_view().
//  */
// function gmp_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
//   $element  = array();
//   $settings = $display['settings'];
//   $location = $settings['gmp_location'];
//   $width    = $settings['gmp_width'];
//   $height   = $settings['gmp_height'];
//   $zoom     = $settings['gmp_zoom'];

//   // @todo: Wrap the bunch in a button group if there are more than 1 elements
//   // $num_items = count($items);
//   // $prefix    = '<div class="btn-group" role="group"">';
//   // $suffix    = '</div>';

//   foreach ($items as $delta => $item) {
//     $url = $item['url']; // Getting the actual value
//     $title = '<i class="fa fa-sign-in"> </i><span> ' . $item['title'] . '</span>'; // Getting the actual value
//     $options = array(
//       'html'        => TRUE, // This tells Drupal that we're sending HTML, no plaintxt, otherwise it would encode it
//       'attributes'  => array(
//         'title' => $title,
//         'class' => array(
//           'btn',
//           $type,
//           $size,
//           $pos,
//           'btn-zhh-formatter'
//         ),
//         'role'  => 'button',
//       ),
//     );
//     $link = l($title, $url, $options); // Create the Link
//     $element[$delta]['#markup'] = $link; // Assign it to the #markup of the element
//   }
//   return $element;
// }























// /**
//  * Implements hook_field_widget_info().
//  */
// function gmp_field_widget_info() {
//   return array(
//     'gmp_textfield' => array(
//       'label' => t('Text field'),
//       'field types' => array('gmp'),
//     ),
//   );
// }

// /**
//  * Implements hook_field_widget_form().
//  */
// function gmp_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
//   $element += array(
//     '#type' => 'textfield',
//     '#title' => $element['#title'],
//     '#description' => $element['#description'],
//     '#default_value' => isset($items[$delta]['value']) ? $items[$delta]['value'] : '',
//     '#required' => $element['#required'],
//     '#size' => 17,
//     '#maxlength' => (
//       $field['settings']['country'] == 'int' ?
//         (isset($instance['settings']['gmp_int_max_length']) ? $instance['settings']['gmp_int_max_length'] : NULL)
//         : NULL
//     ),
//   );
//   return array('value' => $element);
// }


























/**
 *
 * Providing a field requires:
 * - Defining a field:
 *   - hook_field_info()
 *   - hook_field_schema()
 *   - hook_field_validate()
 *   - hook_field_is_empty()
 *
 * - Defining a formatter for the field (the portion that outputs the field for
 *   display):
 *   - hook_field_formatter_info()
 *   - hook_field_formatter_view()
 *
 * - Defining a widget for the edit form:
 *   - hook_field_widget_info()
 *   - hook_field_widget_form()
 *
 * url
 * button_text
 * button_icon
 *
 *
 *
 * @var string
 */


/**
 * Implements hook_field_info().
 * Provides the description of the field.
 */
function gmp_field_info() {
  return array(
    'gmp' => array(
      'label' => t('Google Maps Field'),
      'description' => t('This field stores a custom google map.'),
      'default_widget' => 'gmp',
      'default_formatter' => 'gmp',
      'settings' => array(
        'gmp_location' => variable_get('gmp_location'), // Default Values
        'gmp_width'    => variable_get('gmp_width'),
        'gmp_height'   => variable_get('gmp_height'),
        'gmp_zoom'     => variable_get('gmp_zoom')
      ),
      'instance_settings' => array(),
    )
  );
}

/**
 * Implements hook_field_validate().
 *
 * Possible error codes:
 * - 'email_invalid': The email address is not valid
 */
function gmp_field_validate($obj_type, $object, $field, $instance, $langcode, $items, &$errors) {
  // foreach ($items as $delta => $item) {
  //   dpm($instance);
  //   dpm($errors);
  //   // if ($item['url'] != '' && !valid_email_address(trim($item['email']))) {
  //   if ($item['url'] != '' && !valid_url(trim($item['url'], $absolute = FALSE))) {
  //     $message = t('"%url" is not a valid URL', array('%url' => $item['url']));
  //     $errors[$field['field_name']][$langcode][$delta][] = array(
  //       'error' => "url",
  //       'message' => $message,
  //     );
  //   }

  //   if ($item['title'] != '') {
  //     $message = t('"%title" is not a valid Title', array('%title' => $item['title']));
  //     $errors[$field['field_name']][$langcode][$delta][] = array(
  //       'error' => "title",
  //       'message' => $message,
  //     );
  //   }
  //   dpm($errors);
  // }
}

/**
 * Implements hook_field_is_empty().
 *
 * hook_field_is_emtpy() is where Drupal asks us if this field is empty.
 * Return TRUE if it does not contain data, FALSE if it does. This lets
 * the form API flag an error when required fields are empty.
 */
function gmp_field_is_empty($item, $field) {
  return empty($item['gmp_api_key']) && (string) $item['gmp_api_key'] !== '0';
}

/**
 * Implements hook_field_formatter_info().
 *
 * We need to tell Drupal that we have two different types of formatters
 * for this field. One will change the text color, and the other will
 * change the background color.
 *
 * @see field_example_field_formatter_view()
 */
function gmp_field_formatter_info() {
  $info = array(
    'gmp' => array(
      'label' => t('Google Map'),
      'field types' => array('gmp'),
      'description' => t('Display a Google Map'),
    ),
  );
  return $info;
}

/**
 * Implements hook_field_formatter_view().
 *
 * @see field_example_field_formatter_info()
 */
function gmp_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $settings = $display['settings'];

  switch ($display['type']) {
    // Override check plain
    case 'gmp':
      $last_item = count($items);
      foreach ($items as $delta => $item) {
        // $icon = ($item['icon'] !== 'none') ? '<i class="fa ' . $item['icon'] . '"></i>' : '';
        // $size = ($item['size'] !== 'default') ? '<i class="fa ' . $item['icon'] . '"></i>' : '';
        // $group_prefix = ($delta === 0) ? '<div class="btn-group" role="group">' : '';
        // $group_suffix = ($delta === $last_item) ? '</div>' : '';
        $element [$delta] = array(
          // '#markup' => $group_prefix . '<a class="btn ' . $item['style'] . ' ' . $item['size'] . '" href="' . $item['url'] . '" role="button">' . $icon . ' ' . $item['title'] . '</a>' . $group_suffix,
          '#markup' => '
          <iframe
            width="' . $item['gmp_width'] . '"
            height="' . $item['gmp_height'] . '"
            frameborder="' . $item['gmp_frameborder'] . '"
            style="border:0"
            src="https://www.google.com/maps/embed/v1/place?key=' . $item['gmp_api_key'] . '&zoom=' . $item['gmp_zoom'] . '&q=' . $item['gmp_location'] . '" allowfullscreen>
          </iframe>'
        );
      }
    break;
  }
  return $element;
}

/**
 * Implements hook_field_widget_info().
 * Expose Field API widget types.
 */
function gmp_field_widget_info() {
  return array(
    'gmp' => array(
      'label' => t('Custom Google Map'),
      'field types' => array('gmp'),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 *
 * hook_widget_form() is where Drupal tells us to create form elements for
 * our field's widget.
 */
function gmp_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $widget = $element;
  $widget['#delta'] = $delta;

  // Make this a fieldset with the three text fields.
  $widget += array(
    '#type' => 'fieldset',
    // '#element_validate' => array('gmp_validate'),
    // #delta is set so that the validation function will be able
    // to access external value information which otherwise would be
    // unavailable.
    '#delta' => $delta,
  );

  $widget['gmp_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Location'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#description' => t('The location defines the place to highlight on the map. It accepts a location as either a place name, address, or place ID.'),
    '#default_value' => variable_get('gmp_location')
  );
  $widget['gmp_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#size' => 8,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#description' => t('In % or px'),
    '#default_value' => variable_get('gmp_width')
  );
  $widget['gmp_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#size' => 8,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#description' => t('In % or px'),
    '#default_value' => variable_get('gmp_height')
  );
  $widget['gmp_zoom'] = array(
    '#type' => 'select',
    '#title' => t('Zoom Area'),
    '#description' => t('Accepted values range from 0 (the whole world) to 21 (individual buildings).'),
    '#default_value' => variable_get('gmp_zoom'),
    '#options' => _gmp_zoom()
  );

  return $widget;
}
