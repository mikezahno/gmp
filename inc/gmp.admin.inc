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

  $form['gmp']['gmp_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter your API Key'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#description' => t('Input your API Key'),
    '#default_value' => variable_get('gmp_api_key')
  );

  // $position = variable_get('gmp_position');
  // $position_options = array(
  //   'top-left'     => t('Top Left'),
  //   'top-right'    => t('Top Right'),
  //   'bottom-left'  => t('Bottom Left'),
  //   'bottom-right' => t('Bottom Right'),
  // );

  // $form['gmp']['gmp_position'] = array(
  //   '#type'          => 'select',
  //   '#title'         => t('Widget position'),
  //   '#description'   => t('Select where on the screen the gmp widget should appear'),
  //   '#options'       => $position_options,
  //   '#default_value' => $position ? $position : 'top-left',
  //   '#states'        => array(
  //     'visible'      => array(
  //       ':input[name="toggle_gmp"]' => array('checked' => TRUE),
  //     ),
  //   ),
  // );

  // $adminpage = variable_get('gmp_adminpage');
  // $form['gmp']['gmp_adminpage'] = array(
  //   '#type'          => 'checkbox',
  //   '#title'         => t('Widget in admin mode'),
  //   '#description'   => t('Check the box to show the widget on administration pages.'),
  //   '#default_value' => $adminpage,
  //   '#states'        => array(
  //     'visible'      => array(
  //       ':input[name="toggle_gmp"]' => array('checked' => TRUE),
  //     ),
  //   ),
  // );

  // $breakpoints = variable_get('gmp_breakpoints');
  // $form['gmp']['gmp_breakpoints'] = array(
  //   '#type'          => 'checkbox',
  //   '#title'         => t('Show Twitter Bootstrap 3.x Breakpoints'),
  //   '#description'   => t('Check the box to show Twitter Bootstrap 3.x Breakpoints. Uncheck it to hide em.'),
  //   '#default_value' => variable_get('gmp_breakpoints'),
  //   '#states'        => array(
  //     'visible'      => array(
  //       ':input[name="toggle_gmp"]' => array('checked' => TRUE),
  //     ),
  //   ),
  // );

  return system_settings_form($form);
}
