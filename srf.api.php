<?php

/**
 * @file
 * Hooks provided by the "Semi-required Field" module.
 */
/**
 * @addtogroup hooks
 * @{
 */

/**
 * List function to alter field widgets.
 *
 * @return array An associative array whose keys are field types and
 *    whose values are an associative array containing:
 *   - "callback" : callback function name to alter field widgets
 */
function hook_srf_alter_widget() {
  $alter_widget = array();

  $alter_widget['text_long'] = array(
    'callback_alter' => 'srf_text_long_alter_widget',
    'callback_validate' => 'srf_text_long_validate',
  );

  return $alter_widget;
}

/**
 * Alter existant widget alter function name.
 */
function hook_srf_alter_widget_alter(&$alter_widget) {
  // You can modify the widget alter function for one or more field types.
}

/**
 * Alter existant widget add a validate function.
 */
function hook_srf_alter_validate($element, &$form_state, $form) {
  // You can modify the widget alter function for one or more field types.
}

/**
 * @} End of "addtogroup hooks".
 */

