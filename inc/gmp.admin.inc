<?php

/**
 * @file
 * Admin page callbacks for the gmp module.
 */

/**
 * gmp configuration page.
 */
function gmp_admin_settings_form() {
  $form['gmp'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Gmp Settings'),
    '#weight'      => 20,
    '#tree'        => FALSE,
  );

  $form['gmp_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps API Key.'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#description' => t('Enter your Google Maps API Key.'),
    '#default_value' => variable_get('gmp_api_key')
  );

  $form['gmp']['gmp_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Location'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
    '#description' => t('The location defines the place to highlight on the map. It accepts a location as either a place name, address, or place ID.'),
    '#default_value' => variable_get('gmp_location')
  );
  $form['gmp']['gmp_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#size' => 8,
    '#maxlength' => 10,
    '#required' => FALSE,
    '#description' => t('In % or px'),
    '#default_value' => variable_get('gmp_width')
  );
  $form['gmp']['gmp_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#size' => 8,
    '#maxlength' => 10,
    '#required' => FALSE,
    '#description' => t('In % or px'),
    '#default_value' => variable_get('gmp_height')
  );
  $form['gmp']['gmp_zoom'] = array(
    '#type' => 'select',
    '#title' => t('Zoom Area'),
    '#description' => t('Accepted values range from 0 (the whole world) to 21 (individual buildings).'),
    '#default_value' => variable_get('gmp_zoom'),
    '#options' => _gmp_zoom()
  );
  $form['gmp']['gmp_frameborder'] = array(
    '#type' => 'checkbox',
    '#title' => t('Frameborder'),
    '#description' => t('Show a frameborder.'),
    '#default_value' => variable_get('gmp_frameborder')
  );

  return system_settings_form($form);
}
