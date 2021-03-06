<?php

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
        // Default Values
        'gmp_location'    => variable_get('gmp_location'),
        'gmp_width'       => variable_get('gmp_width'),
        'gmp_height'      => variable_get('gmp_height'),
        'gmp_zoom'        => variable_get('gmp_zoom')
      ),
      'instance_settings' => array(),
    )
  );
}

// /**
//  * Implements hook_field_validate().
//  *
//  * Possible error codes:
//  * - 'email_invalid': The email address is not valid
//  */
// function gmp_field_validate($obj_type, $object, $field, $instance, $langcode, $items, &$errors) {
//   foreach ($items as $delta => $item) {
//     dpm($instance);
//     dpm($errors);
//     // if ($item['url'] != '' && !valid_email_address(trim($item['email']))) {
//     if ($item['gmp_location'] == '') {
//       $message = t('Please enter a valid location.', array('%gmp_location' => $item['gmp_location']));
//       $errors[$field['field_name']][$langcode][$delta][] = array(
//         'error' => "gmp_location",
//         'message' => $message,
//       );
//     }

//     if ($item['gmp_width'] == '') {
//       $message = t('Please enter a valid width in px or %.', array('%gmp_width' => $item['gmp_width']));
//       $errors[$field['field_name']][$langcode][$delta][] = array(
//         'error' => "gmp_width",
//         'message' => $message,
//       );
//     }

//     if ($item['gmp_height'] == '') {
//       $message = t('Please enter a valid height in px.', array('%gmp_height' => $item['gmp_height']));
//       $errors[$field['field_name']][$langcode][$delta][] = array(
//         'error' => "gmp_height",
//         'message' => $message,
//       );
//     }
//     dpm($errors);
//   }
// }

/**
 * Implements hook_field_is_empty().
 *
 * hook_field_is_emtpy() is where Drupal asks us if this field is empty.
 * Return TRUE if it does not contain data, FALSE if it does. This lets
 * the form API flag an error when required fields are empty.
 */
function gmp_field_is_empty($item, $field) {
  return empty($item['gmp_location']) && (string) $item['gmp_location'] !== '0';
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
        $prefix = ($delta === 0) ? '<div class="map-group" role="group">' : '';
        $suffix = ($delta === $last_item) ? '</div>' : '';
        $element [$delta] = array(
          // '#markup' => $group_prefix . '<a class="btn ' . $item['style'] . ' ' . $item['size'] . '" href="' . $item['url'] . '" role="button">' . $icon . ' ' . $item['title'] . '</a>' . $group_suffix,
          '#markup' => $prefix . '
          <iframe
            width="' . $item['gmp_width'] . '"
            height="' . $item['gmp_height'] . '"
            frameborder="0"
            style="border:0"
            src="https://www.google.com/maps/embed/v1/place?key=' . variable_get('gmp_api_key') . '&zoom=' . $item['gmp_zoom'] . '&q=' . $item['gmp_location'] . '" allowfullscreen>
          </iframe>' . $suffix
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
    '#required' => FALSE,
    '#description' => t('The location defines the place to highlight on the map. It accepts a location as either a place name, address, or place ID.'),
    '#default_value' => isset($items[$delta]['gmp_location']) ? $items[$delta]['gmp_location'] : NULL
  );
  $widget['gmp_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#size' => 8,
    '#maxlength' => 10,
    '#required' => FALSE,
    '#description' => t('In % or px'),
    '#default_value' => isset($items[$delta]['gmp_width']) ? $items[$delta]['gmp_width'] : NULL
  );
  $widget['gmp_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#size' => 8,
    '#maxlength' => 10,
    '#required' => FALSE,
    '#description' => t('In % or px'),
    '#default_value' => isset($items[$delta]['gmp_height']) ? $items[$delta]['gmp_height'] : NULL
  );
  $widget['gmp_zoom'] = array(
    '#type' => 'select',
    '#title' => t('Zoom Area'),
    '#description' => t('Accepted values range from 0 (the whole world) to 21 (individual buildings).'),
    '#default_value' => isset($items[$delta]['gmp_zoom']) ? $items[$delta]['gmp_zoom'] : NULL,
    '#options' => _gmp_zoom()
  );

  return $widget;
}
