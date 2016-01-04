<?php


/**
 * Implementation of hook_field_info().
 */
function gmp_field_info() {
  return array(
    'gmp' => array(
      'label' => t('Gmp'),
      'settings' => array(
        'gmp_location' => variable_get('gmp_location'), // Default Values
        'gmp_width'    => variable_get('gmp_width'),
        'gmp_height'   => variable_get('gmp_height'),
        'gmp_zoom'     => variable_get('gmp_zoom')
      ),
      'default_formatter' => 'gmp',
      'default_widget' => 'gmp_field',
      'property_type' => 'text',
    ),
  );
}


/**
 * Implements hook_field_settings_form().
 */
function gmp_field_settings_form($field, $instance, $has_data) {
  $settings = $field['settings'];

  $form = array();
  $form['gmp_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Location'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#description' => t('The location defines the place to highlight on the map. It accepts a location as either a place name, address, or place ID.'),
    '#default_value' => variable_get('gmp_location')
  );
  $form['gmp_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#size' => 8,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#description' => t('In % or px'),
    '#default_value' => variable_get('gmp_width')
  );
  $form['gmp_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#size' => 8,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#description' => t('In % or px'),
    '#default_value' => variable_get('gmp_height')
  );
  $form['gmp_zoom'] = array(
    '#type' => 'select',
    '#title' => t('Zoom Area'),
    '#description' => t('Accepted values range from 0 (the whole world) to 21 (individual buildings).'),
    '#default_value' => variable_get('gmp_zoom'),
    '#options' => _gmp_zoom()
  );

  return $form;
}



/**
 * Implements hook_field_formatter_info().
 */
function gmp_field_formatter_info() {
  $info = array(
    'gmp_field' => array(
      'label' => t('Gmp Textfield'),
      'field types' => array('gmp'),
      'description' => t('Gmp Textfield'),
      'settings'  => array( //Array of the settings we'll create
        'gmp_location' => variable_get('gmp_location'), // Default Values
        'gmp_width'    => variable_get('gmp_width'),
        'gmp_height'   => variable_get('gmp_height'),
        'gmp_zoom'     => variable_get('gmp_zoom')
      ),
    ),
  );
  return $info;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function gmp_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $element = array();
  $element['gmp_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Location'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#description' => t('The location defines the place to highlight on the map. It accepts a location as either a place name, address, or place ID.'),
    '#default_value' => variable_get('gmp_location')
  );
  $element['gmp_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#size' => 8,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#description' => t('In % or px'),
    '#default_value' => variable_get('gmp_width')
  );
  $element['gmp_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#size' => 8,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#description' => t('In % or px'),
    '#default_value' => variable_get('gmp_height')
  );
  $element['gmp_zoom'] = array(
    '#type' => 'select',
    '#title' => t('Zoom Area'),
    '#description' => t('Accepted values range from 0 (the whole world) to 21 (individual buildings).'),
    '#default_value' => variable_get('gmp_zoom'),
    '#options' => _gmp_zoom()
  );
  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function gmp_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $summary = t('Button size: @size, Button Type: @type, Button Position: @pos', array(
    '@location' => $settings['gmp_location'],
    '@width'    => $settings['gmp_width'],
    '@height'   => $settings['gmp_height'],
    '@zoom'     => $settings['gmp_zoom'],

  ));
  return $summary;
}

/**
 * Implements hook_field_formatter_view().
 */
function gmp_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element  = array();
  $settings = $display['settings'];
  $location = $settings['gmp_location'];
  $width    = $settings['gmp_width'];
  $height   = $settings['gmp_height'];
  $zoom     = $settings['gmp_zoom'];

  // @todo: Wrap the bunch in a button group if there are more than 1 elements
  // $num_items = count($items);
  // $prefix    = '<div class="btn-group" role="group"">';
  // $suffix    = '</div>';

  foreach ($items as $delta => $item) {
    $url = $item['url']; // Getting the actual value
    $title = '<i class="fa fa-sign-in"> </i><span> ' . $item['title'] . '</span>'; // Getting the actual value
    $options = array(
      'html'        => TRUE, // This tells Drupal that we're sending HTML, no plaintxt, otherwise it would encode it
      'attributes'  => array(
        'title' => $title,
        'class' => array(
          'btn',
          $type,
          $size,
          $pos,
          'btn-zhh-formatter'
        ),
        'role'  => 'button',
      ),
    );
    $link = l($title, $url, $options); // Create the Link
    $element[$delta]['#markup'] = $link; // Assign it to the #markup of the element
  }
  return $element;
}























/**
 * Implements hook_field_widget_info().
 */
function gmp_field_widget_info() {
  return array(
    'gmp_textfield' => array(
      'label' => t('Text field'),
      'field types' => array('gmp'),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function gmp_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $element += array(
    '#type' => 'textfield',
    '#title' => $element['#title'],
    '#description' => $element['#description'],
    '#default_value' => isset($items[$delta]['value']) ? $items[$delta]['value'] : '',
    '#required' => $element['#required'],
    '#size' => 17,
    '#maxlength' => (
      $field['settings']['country'] == 'int' ?
        (isset($instance['settings']['gmp_int_max_length']) ? $instance['settings']['gmp_int_max_length'] : NULL)
        : NULL
    ),
  );
  return array('value' => $element);
}
